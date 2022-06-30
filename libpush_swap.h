/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:28:04 by phijano-          #+#    #+#             */
/*   Updated: 2022/06/29 13:54:24 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_SWAP_H
# define LIBPUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

int		ft_check_args(int args, char **arg, int *stack_a, int length);
int		*ft_convert_index(int length, int *stack_a);
int		*ft_sort(int length, int *stack_a);
int		ft_is_sorted(int length, int *stack_a);
int		ft_best_start(int length, int *stack_a);
void	ft_sort_many_alg(int length, int *stack_a, int *stack_b, int start);
int		ft_swap_push(int length, int *stack_a, int *stack_b, int pushed);
void	ft_push_back(int length, int *stack_a, int *stack_b);
int		ft_count_rotations(int lenght, int *stack_a, int *stack_b, int count_b);
void	ft_sa(int *stack_a, int show);
void	ft_sb(int *stack_b, int show);
void	ft_ss(int *stack_a, int *stack_b, int show);
void	ft_pa(int length, int *stack_a, int *stack_b, int show);
void	ft_pb(int length, int *stack_a, int *stack_b, int show);
void	ft_ra(int length, int *stack_a, int show);
void	ft_rb(int length, int *stack_b, int show);
void	ft_rr(int length, int *stack_a, int *stack_b, int show);
void	ft_rra(int length, int *stack_a, int show);
void	ft_rrb(int length, int *stack_b, int show);
void	ft_rrr(int length, int *stack_a, int *stack_b, int show);
void	ft_push_lowest(int length, int *stack_a, int *stack_b);
void	ft_rr_many(int length, int *stack_a, int *stack_b, int amount);
void	ft_rrr_many(int length, int *stack_a, int *stack_b, int amount);
int		ft_min(int length, int *stack);
int		ft_count_words(const char *str, char c);
int		ft_count_total_words(int args, char **arg);
int		ft_lower(int a, int b);
int		ft_big(int a, int b);
int		ft_get_index(int length, int *stack_a, int number);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);

#endif
