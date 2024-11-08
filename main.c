#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"

int	main()
{
	int		fd;
	char	*line;	
	
	ft_putendl_fd("Hello, World!", STDOUT_FILENO);
	ft_printf("%d\n", ft_isalpha('a'));
	fd = open("test.txt", O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}
	while ((line = get_next_line(fd)) != NULL) {
		ft_printf("%s\n", line);
		free(line);
	}	
	close(fd);
	return 0;
}
