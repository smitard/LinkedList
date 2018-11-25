$ErrorActionPreference = "SilentlyContinue"

Write-host "Do you remember the path to your LinkedList.exe file?";
Write-host "Type Yes if you do. Otherwise type No";

while(1){

$quiz = Read-Host;

if ($quiz -eq 'Yes' -or $quiz -eq 'No'){
         
         if($quiz -eq 'Yes' -or $quiz -eq 'yes'){
            Write-host "Please enter the full path to your LinkedList.exe";
            Write-host "Example: D:\Nudes\LinkedList.exe";
            $LinkedList = Read-Host;
            & $LinkedList;
            Write-host "If nothing happened check the correctness of entered path";
         }
         if($quiz -eq 'No' -or $quiz -eq 'no'){
            Write-host "We are going to search for LinkedList.exe on your computer";
            Write-host "Make yourself a tea and turn on Interstellar movie `nbecause it is going to take a while";
            $drives = Get-PSDrive -PSProvider 'FileSystem';
            foreach ($Drive in $drives){
                $LinkedList = Get-ChildItem -Path $Drive.Root -Include LinkedList.exe -Recurse -File;
            }
            $a = $LinkedList[0];
            & $a;
             Write-host "If nothing happened make sure LinkedList.exe exists on your computer";
         }
    exit;
}
else {
        Write-host "Please enter Yes or No";
}
}