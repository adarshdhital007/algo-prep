# Set the base directory where the folders are located
$baseDirectory = "E:\demo"

# Set the names of the .cpp files to be added
$cppFiles = @("1.cpp", "2.cpp", "3.cpp")  # Add more file names if needed

# Get a list of folder names in the base directory
$folderNames = Get-ChildItem -Path $baseDirectory -Directory | Select-Object -ExpandProperty Name

# Loop through each folder name
foreach ($folderName in $folderNames) {
    # Create the full path of the folder
    $folderPath = Join-Path -Path $baseDirectory -ChildPath $folderName

    # Loop through each .cpp file name
    foreach ($cppFile in $cppFiles) {
        # Create the full path of the .cpp file
        $cppFilePath = Join-Path -Path $folderPath -ChildPath $cppFile

        # Check if the .cpp file already exists in the folder
        if (-not (Test-Path $cppFilePath -PathType Leaf)) {
            # Create a new empty .cpp file
            New-Item -Path $cppFilePath -ItemType File | Out-Null
            Write-Host "Added $cppFile to $folderName"
        }
    }
}
