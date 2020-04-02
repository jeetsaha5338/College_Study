echo "Enter the Range:"
read n
a=0
b=1
echo "$a"
echo "$b"
c=`expr  $a + $b`
while [ $c -lt $n ]
do
	echo "$c"

	a=$b
	b=$c
	c=`expr  $a + $b`
done
