# Name: Joshua Welch
#
#Modify the variables according to your system
#
#Set a variable for the location of the CSV file. For example, if CSV file
#is loacted in C:\PowerShell
$FilePath = "C:\PowerShell\"
#
#Set a variable for the CSV file name. 
#$csvfile = 'StudentsShortList.csv'
$csvfile = 'Students-Day3.csv'
#
#Set a variable for the OU where user accounts will be stored
#For example, "OU=Student Accounts,OU=IoT University,DC=CST412Project,DC=local"
$OUPathForAccounts = "OU=Student Accounts,OU=IoT University/Student Accounts,DC=welch, DC=local"

#Set a variable for the OU where user Groups will be stored
#For example, "OU=Course Groups,OU=IoT University,DC=CST412Project,DC=local"
$OUPathForGroups = "OU=Course Groups,OU=IoT University/Student Accounts,DC=welch, DC=local"
#
#Set a variable to the location of users home directory
$HomeDirectory = "\\WELCHSERVER\StudentsHomeDirectory\"
#

Try 
{ 
  Import-Module ActiveDirectory -ErrorAction Stop 
} 
Catch 
{ 
  Write-Host "[ERROR]`t ActiveDirectory Module couldn't be loaded. Script will stop!" 
  Exit 1 
}

$Users = Import-Csv -Delimiter "," -Path ($FilePath + $csvfile)            
foreach ($User in $Users)            
{            
    $Displayname = $User.Firstname + " " + $User.Lastname + $User.'Student ID'            
    $UserFirstname = $User.Firstname            
    $UserLastname = $User.Lastname                       
    $SAM = $User."Student ID"            
    $UPN = $User."Student ID" + "@" + "welch.local"                        
    $Password = $User.DOB            
     try{
     New-ADUser -Name "$Displayname" -DisplayName "$Displayname" -SamAccountName $SAM -UserPrincipalName $UPN -GivenName "$UserFirstname" -Surname "$UserLastname" -AccountPassword (ConvertTo-SecureString $Password -AsPlainText -Force) -Enabled $true -Path "$OUPathForAccounts" -ChangePasswordAtLogon $false –PasswordNeverExpires $true             
     Set-ADUser $SAM -HomeDrive "Z:" -HomeDirectory ($HomeDirectory + $SAM)
     NEW-ITEM –path ($HomeDirectory + $SAM) -type directory -force
     } catch{ }
     try{
     New-ADGroup -GroupScope Global -Path $OUPathForGroups -Name $User.Class
     } catch{ }
     try{
     Add-ADGroupMember -Identity $User.Class -Member $SAM
     } catch{ }
#
#  Extra Credit:
#
     if($User.Status -eq 'X' -or $User.Status -eq 'D' ){
     Remove-ADGroupMember -Identity $User.Class -Member $SAM -Confirm:$false
     $ClassCount= ((GET-ADUSER –Identity $SAM).memberof).count
     if($ClassCount -eq 0){
     Remove-ADUser -Identity $SAM -Confirm:$false
     Remove-Item ($HomeDirectory + $SAM) -Recurse -Force
     }
     }
}