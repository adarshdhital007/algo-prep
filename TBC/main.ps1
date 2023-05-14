$baseDirectory = "src"
$cppFiles = @("", "", "")
$folderNames = Get-ChildItem -Path $baseDirectory -Directory | Select-Object -ExpandProperty Name

foreach ($folderName in $folderNames) {
    $folderPath = Join-Path -Path $baseDirectory -ChildPath $folderName

    foreach ($cppFile in $cppFiles) {
        $cppFilePath = Join-Path -Path $folderPath -ChildPath $cppFile

        if (-not (Test-Path $cppFilePath -PathType Leaf)) {
            New-Item -Path $cppFilePath -ItemType File | Out-Null
            Write-Host "Added $cppFile to $folderName"
        }
    }
}
