clear
for (( ; ; ))
do
	# cd ../libft/ && make re clean
	# clear
	# cp libft.* ../printf/
	# cd ../printf/
	gcc ft_printf.c ft_utils.c libft.a -W -W -W 
	sleep 0.3
	./a.out
	sleep 2
	clear
done

