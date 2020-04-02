echo "Enter the 3 sides: "

read x
read y
read z

if  [	`expr  $x  +  $y`  -gt $z	]
	then 	
	if  [ `expr $x  +  $z` -gt $y ]
	then 
	if	[ `expr $y	+ $z ` -gt $x	]	
		then echo "Posible"
		else echo "Not posible"
	fi
	else echo "Not posible"
	fi
	else  echo "Not posible"
	fi
