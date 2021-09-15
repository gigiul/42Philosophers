#include "includes/philo.h"

int		init_mutex(t_main *main)
{
	int	i;

	i = -1;
	while (++i < main->n_philo)
		pthread_mutex_init(&main->forks[i], NULL);
	pthread_mutex_init(&main->finished_meal, NULL);
	pthread_mutex_init(&main->printer, NULL);
	pthread_mutex_init(&main->death, NULL);
	return (1);
}

int		init_philos(t_main	*main)
{
	int	i;
	
	i = -1;
	main->philo = malloc(sizeof(pthread_mutex_t) * main->n_philo);
	if (!main->philo)
		return (0);
	while (++i < main->n_philo)
	{
		main->philo[i].id = i + 1;
		main->philo[i].status = 0;
		main->philo[i].main = main;
		main->philo[i].meal_taken = 0;
		main->philo[i].start_eat = 0;
		main->philo[i].left_fork = &main->forks[i];
		if (i == 0)
			main->philo[i].right_fork = &main->forks[main->n_philo - 1];
		else
			main->philo[i].right_fork = &main->forks[i - 1];
	}
	return (1);
}

int		init_forks(t_main *main)
{
	main->forks = malloc(sizeof(pthread_mutex_t) * main->n_philo);
	if (!main->forks)
	{
		//free_philo(main);
		return (0);
	}
	return (1);
}

int		check_parameters(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_isnumb(argv[i]) == 0 || ft_atoi(argv[i]) <= 0)
			return (0);
	}
	return (1);
}

int	init(t_main *main, int argc, char **argv)
{
	if (check_parameters(argc, argv) == 1)
	{
		main->n_philo = ft_atoi(argv[1]);
		main->t_die = ft_atoi(argv[2]);
		main->t_eat = ft_atoi(argv[3]);
		main->t_sleep = ft_atoi(argv[4]);
		main->nb_meal = 0;
		if (argc == 6)
			main->nb_meal = ft_atoi(argv[5]);
		main->nb_finished_meal = 0;
		main->dead = 0;
		main->philo = NULL;
		main->forks = NULL;
		if ((init_forks(main) && init_philos(main) && init_mutex(main) == 0))
			return (0);
		return (1);
	}
	return (0);
}

int main (int argc, char **argv)
{
	t_main	main;

	if (argc >= 5 && argc <= 6)
	{
		if (!init(&main, argc, argv))
		{
			printf("Invalid arguments\n");
			return (1);
		}
		//launch_threads(&main);
		//launch_monitoring(&main);
		//free_all(&main);
	}
	else
	{
		printf("Invalid number of parameters\n");
		return (1);
	}
	return (0);
}