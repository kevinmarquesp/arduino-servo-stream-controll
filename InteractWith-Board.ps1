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
            VendorDir = "";
        };

        Board = @{
            ShortName = "uno";
            LongName = "arduino:avr:uno";
            Port = "COM9";
            BaudRate = "115200";
        };

        ArduinoCLI = @{
            Command = "arduino-cli.exe";
            Flags = "";
        };
    }
)

$ArduinoCLI = $ConnectionData.ArduinoCLI
$Project = $ConnectionData.Project
$Board = $ConnectionData.Board

if ($Compile) {
    & $ArduinoCLI.Command compile $ArduinoCLI.Flags`
        --fqbn $Board.LongName`
        --port $Board.Port`
        $Project.SketchDir
}

if ($Upload) {
    & $ArduinoCLI.Command compile $ArduinoCLI.Flags`
        --fqbn $Board.LongName`
        --port $Board.Port`
        --upload $Project.SketchDir
}

if ($Test) {
    & $ArduinoCLI.Command compile $ArduinoCLI.Flags`
        --fqbn $Board.LongName`
        --port $Board.Port`
        --upload $Project.TestsDir

    $Conn = New-Object System.IO.Ports.SerialPort $Board.Port, $Board.BaudRate, None, 8, one
    $Conn.DtrEnable = $True

    $Conn.Open()
    Start-Sleep -Seconds 2

    while ($True) {
        $Data = $Conn.ReadExisting()

        if ($Data.Length -ne 0) {
            Write-Host $Data
        }
    }

    $Conn.Close()
}