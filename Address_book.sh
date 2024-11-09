#!/bin/sh
create()
{
echo "Enter the address book name"
read ab

if [-e "$ab" ] 
then
 echo "Error, File "$ab"  is existing !"
else 
 touch $ab
fi

}


display()
{
echo "Enter the address book name"
read ab

if [-e "$ab" ]
then
 cat $ab;
else 
echo "Error, File "$ab"  is not existing !"
fi

}

insert()
{
 echo "Enter the address book name"
read ab

if [-e "$ab"]
then
echo "Enter the email "
read email
len='cat $ab|grep $email|wc -w'

 if [$len -gt 0 ]
 then 
  echo "The data is alreadu existing in file"
 else
  echo "Enter last name , first name and mobile"
  read lname fname mobile
  
  echo "$lname $fname $email $mobile">>"$ab"
  
  echo "Record inserted"
  fi
 else
  echo "File is not existing "
  fi
}

modify()
{
echo "Enter the address book name"
read ab

if [-e "$ab" ]
then
echo "Enter the email "
read email
len='cat $ab|grep $email|wc -w'

 if [$len -gt 0]
 then 
   echo "Enter the modified last name , first name and mobile"
   read lname fname mobile
  
   new='echo $lname $fname $email $mobile'
   old='cat $ab|$email'
   
   echo "Old Record : $old"
   echo "New Record : $new"
 
 sed -i s/$old/$new/g "$ab"	
 echo "Record Modified"
 
 else 
 echo "Record not found"
 fi
 else "File not found"
 
 fi
 }
 
 
delete()
{
echo "Enter the address book name"
read ab

if [-e "$ab"]
then
echo "Enter the email "
read email
len='cat $ab|grep $email|wc -w'

 if [$len -gt 0]
 then 
   
  
   
   old='cat $ab|$email'
 
 sed -i s/$old//g "$ab"	
 echo "Record Deleted"
 
 else 
 echo "Record not found"
 fi
 else "File not found"
 
 fi
 }
 
# Main loop
while true; do
    echo "1) Create"
    echo "2) Display"
    echo "3) Insert"
    echo "4) Modify"
    echo "5) Delete"
    echo "6) Exit"
    
    echo "Enter your choice:"
    read choice
    
    case $choice in 
        1) create ;;
        2) display ;;
        3) insert ;;
        4) modify ;; 
        5) delete ;; 
        6) echo "Exiting..."; exit 0 ;;
        *) echo "Wrong choice!" ;;
    esac
done


