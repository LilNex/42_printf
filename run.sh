clear
for (( ; ; ))
do
	# cd ../libft/ && make re clean
	# clear
	# cp libft.* ../printf/
	# cd ../printf/
	gcc ft_printf.c ft_utils.c ft_utils2.c libft.a -W -W -W 
	sleep 0.3
	./a.out
	sleep 2
	clear
done

