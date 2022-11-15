clear
for (( ; ; ))
do
	# cd ../libft/ && make re clean
	# clear
	# cp libft.* ../printf/
	# cd ../printf/
	gcc ft_printf.c ft_utils.c ft_utils2.c -W -W -W 
	sleep 0.6
	clear

	./a.out
	sleep 2
	clear
done

