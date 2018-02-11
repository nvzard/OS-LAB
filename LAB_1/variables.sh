#Pre-defined variables
echo $HOME
echo $PWD

#Positional Variables
echo $1 $2

#change value of positional variables
set 99 $2
echo $1 $2

$1=69
echo $1 $2

#User Defined Variables
echo 'Enter two values:'
read a b
echo $a $b
echo 'Bonus variable:'
c=10
echo $c
