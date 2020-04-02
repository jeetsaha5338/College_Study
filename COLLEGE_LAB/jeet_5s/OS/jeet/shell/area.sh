echo "Enter 3 Sides:"
read a
read b
read c
x=`echo "scale = 3;$a+$b+$c"|bc`
s=`echo "scale = 3;$x/2"|bc`
n=`echo "scale = 3;($s*($s-$a)*($s-$b)*($s-$c))"|bc`
area=`echo "scale = 3;sqrt($n)"|bc`
ca=`echo "scale = 3;$area>0"|bc`
if [ $ca -eq 1 ]
then echo "$area"
else echo "not posible"
fi
