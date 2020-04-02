echo "Enter the Number:"
read c
x=$c
sum=0
n=0

while [ $x -gt 0 ]
do 
r=`expr $x % 10`
sum=`expr $sum + \( $r \* $r \* $r \)`
x=`expr $x / 10`
done
if  [ $sum -eq $c ]
then 
echo "A"
else
echo "NA"
fi
