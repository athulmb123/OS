echo -n "Enter a number : "
read n
c=$n
fact=1
while [ $n -gt 0 ]; do
	fact=$((fact * n))
	n=$((n - 1))
done
echo "The factorial of $c is $fact"
