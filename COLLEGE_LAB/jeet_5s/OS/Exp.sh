echo "Enter x & n:"
read x
read n
if [ $n -eq 1 ]
	then
	a=`expr 1 + \( $x \* $x \)`
	echo "$a" 
elif [ $n -eq 2 ]
	then
	a=`expr 1 + \( $x / $n \)`
	echo "$a"
elif [ $n -eq 3 ]
	then
	a=`expr 1 + \( 2 \* $x \)`
	echo "$a"
else
	 a=`expr 1 + \( $x \* $n \)`
	echo "$a"
fi
