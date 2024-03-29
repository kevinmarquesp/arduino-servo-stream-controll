[CmdletBinding()]
param (
    [Alias("C", "Comp")]
    [Switch]
    $Compile=$False,

    [Alias("U", "Up")]
    [Switch]
    $Upload=$False,

    [Alias("T")]
    [Switch]
    $Test=$False,

    [Parameter(Position=0)]
    $ConnectionData=@{
        Project = @{
            SketchDir = "sketch";
            TestsDir = "tests";
        };

        Board = @{
            ShortName = "uno";
            LongName = "arduino:avr:uno";
            Port = "COM9";
            BaudRate = "115200";
        };

        ArduinoCLI = @{
            Command = "arduino-cli.exe";
            Flags = "--library .\vendor\AUnit
                     --library .\vendor\LinkedList
                     --library .\vendor\Servo
                     --library .\vendor\ParallelServo";
        };
    }
)

$ArduinoCLI = $ConnectionData.ArduinoCLI
$Project = $ConnectionData.Project
$Board = $ConnectionData.Board

if ($Compile) {
    $Command = "& $($ArduinoCLI.Command) compile $($ArduinoCLI.Flags)
        --fqbn $($Board.LongName)
        $($Project.SketchDir)" -replace "\r\n *", " "

    Write-Host $Command
    Invoke-Expression $Command
}

if ($Upload) {
    $Command = "& $($ArduinoCLI.Command) compile $($ArduinoCLI.Flags)
        --fqbn $($Board.LongName)
        --port $($Board.Port)
        --upload
        $($Project.SketchDir)" -replace "\r\n *", " "

    Write-Host $Command
    Invoke-Expression $Command
}

if ($Test) {
    $Command = "& $($ArduinoCLI.Command) compile $($ArduinoCLI.Flags)
        --fqbn $($Board.LongName)
        --port $($Board.Port)
        --upload
        $($Project.TestsDir)" -replace "\r\n *", " "

    Write-Host $Command
    Copy-Item -Recurse -Force "$($Project.SketchDir)/src" $Project.TestsDir
    Invoke-Expression $Command

    $Conn = New-Object System.IO.Ports.SerialPort $Board.Port, $Board.BaudRate, None, 8, one
    $Conn.DtrEnable = $True

    $Conn.Open()
    Start-Sleep -Seconds 2

    while ($True) {
        $Data = $Conn.ReadExisting()

        if ($Data.Length -ne 0) {
            Write-Host $Data
        }

        if ([Console]::KeyAvailable) {
            $key = [Console]::ReadKey($true).Key
            if ($key -eq "q") {
                break
            }
        }

        Start-Sleep -Milliseconds 50
    }

    $Conn.Close()
}