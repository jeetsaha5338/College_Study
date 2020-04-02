echo "Enter 3 Sides:"
read a
read b
read c
if [ `expr $a + $b` -gt $c ]
	then 
	if [ `expr $a + $c` -gt $b ]
		then 
		if [ `expr $b + $c` -gt $a ]
			then echo "posible"
			else echo "not posible"
		fi
		else echo "not posible"
	fi
else echo "not posible"
fi
	
