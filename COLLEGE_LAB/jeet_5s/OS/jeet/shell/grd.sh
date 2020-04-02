echo "Enter Marks:"
read m
case $m in
100)	echo "O";;
9[0-9]) echo "O";;
8[0-9]) echo "E";;
7[0-9]) echo "A";;
6[0-9]) echo "B";;
5[0-9]) echo "C";;
[0-4][0-9]) echo "F";;
*)	echo "invalid"
esac



