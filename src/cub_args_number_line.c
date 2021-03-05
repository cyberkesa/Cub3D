#include "cub.h"

void					check_maybe_not_valid_line(char *line, t_cub *cub)
{
	int					i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			return ;
		i++;
	}
	close(cub->fd_for_number_line);
	re_no_free("Error! Global error with map.\n", cub);
}

void					check_valid_argc(int argc, char **argv, t_cub *cub)
{
	int					argv_len;

	argv_len = (int)ft_strlen(argv[1]) - 1;
	if (argv[1][argv_len - 3] != '.'
	&& argv[1][argv_len - 2] != 'c'
	&& argv[1][argv_len - 1] != 'u'
	&& argv[1][argv_len] != 'b')
		re_no_free("Error! Need .cub.\n", cub);
	if (argc == 3 && argv[2][0] == '-'
	&& argv[2][1] == '-' && argv[2][2] == 's'
	&& argv[2][3] == 'a' && argv[2][4] == 'v'
	&& argv[2][5] == 'e' && argv[2][6] == '\0')
		cub->flags.screen = 1;
	else if (argc >= 3)
		re_no_free("Error! Not valide number of arguments.\n", cub);
}

void					parce_number_line(t_cub *cub)
{
	char				*line;

	while (get_next_line(cub->fd_for_number_line, &line) == 1)
	{
		if (line[0] == ' ')
			check_maybe_not_valid_line(line, cub);
		if (line[0] == ' ' || line[0] == '1' || line[0] == ' ')
			cub->map_number_line++;
		cub->fd_number_line++;
		free(line);
	}
	free(line);
}


int						cub_args_and_fd(t_cub *cub, int argc, char **argv)
{
	int					fd;

	if (!argv[1])
		re_no_free("Error argv.\n", cub);
	check_valid_argc(argc, argv, cub);
	fd = open(argv[1], O_RDONLY);
	cub->fd_for_number_line = open(argv[1], O_RDONLY);
	if (cub->fd_for_number_line < 0 || fd < 0)
		re_no_free("Error argv.\n", cub);
	parce_number_line(cub);
	close(cub->fd_for_number_line);
	return (fd);
}
