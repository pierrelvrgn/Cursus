#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class game_board
{
private:
	unsigned const _height, _width, _board_size, _winning_length;
	unsigned _stone_amounts;
	unsigned _current_player;
	unsigned _last_player;

	std::vector<std::vector<unsigned> > _board;

	int	empty_row(unsigned col) const;
	int	occupied_row(unsigned col) const;
public:
	game_board(unsigned height, unsigned width, unsigned winning_length, int depth_limit);
	game_board(game_board const &copy);

	std::vector<int> searched_col;

	int depth_max;

	int	get_board_size() const;
	int	get_stone_amounts() const;
	int	get_width() const;
	std::vector<std::vector<unsigned> > const & get_board() const;

	bool	is_winning_move(unsigned col) const;
	bool	is_losing_move(unsigned col) const;

	void	put_stone(unsigned col);
	void	take_stone(unsigned col);

	void	print_board() const;

	void	test();
};