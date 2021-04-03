/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:33:24 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/03 10:50:59 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"





/*
**
**	During assembly the labels are turned into a distance in bytes (int) relative to current
**	operation that is calling said label.
**
**
**	At the start Virtual machine writes all the champions' codes to the memory block
**	(arena) so that their start positions are evenly distributed. It creates one carrier
**	at the start of each players' code.
**
**
**	Carriers are like pointers that execute code that they are currently pointing to in the
**	memory and move to the next one if the instruction doesn't make it 'jump' somewhere else.
**	They just roam around executing instructions according to the code they are
**	pointing to in the arena. They are neutral and champions don't 'own' them.
**
**
**	PC ('Program counter') is a (personal for every champion) index which shows in
**	what byte of champion's code the execution is in currently. The virtual machine
**	has this index.(?)
**
**
**	The '.cor'-file is just long queue of bytes which starts with the header
**	(128 bytes of program name after which is 2048 bytes of comment) and the rest
**	of the file is all the instructions of the champion in the same order they were
**	is the '.s'-file.
**
**
**
**
**
**	Example of operation 'sti r1,%:live,%1' encoding into hexadecimal:
**
**	0x0b -> opcode of 'sti' in hexadecimal
**	0x68 -> 'coding byte' which is like a heads-up for what types (direct, indirect or registry)
**			of arguments come next. Here's how it comes together:
**
**			r1,  %:live,   %1
**			 |      |      |
**			reg    dir    dir    (rest of the byte is just empty zeroes)
**			 |      |      |      |
**	    	 01     10     10     00     (bits are 01 for registries, 10 for direct and 11 for indirect)
**		      \     |      |     /
**			        01101000 which is 0x68 in hexadecimal
**
**	0x01 -> first argument (r1)
**	0x00 -> second argument (%:live, ':' just means that the following is a name of label)
**	0x0f ->      -||-
**	0x00 -> third argument (%1)
**	0x00 ->      -||-
**	0x00 ->      -||-
**	0x01 ->      -||-
**
**	Resulting bytes in order: 0x0b   0x68   0x01   0x00 0x0f   0x00 0x00 0x00 0x01
**
**
**	As seen above register is given as 1 byte, direct argument (%) as 4 bytes, direct argument
**	with label name after it (%:) as 2 bytes and indirect (just the integer) with 2 bytes.
**
**
**	Example #2 'sti r2,23,%34':
**
**	0x0b -> opcode of 'sti' in hexadecimal
**	0x78 -> 'coding byte':
**
**			r2,    23,    %34
**			 |      |      |
**			reg    ind    dir
**			 |      |      |
**	    	 01     11     10     00
**		      \     |      |     /
**			        01111000 which is 0x78 in hexadecimal
**
**	0x02 -> first argument (r2)
**	0x00 -> second argument (23)
**	0x17 ->      -||-
**	0x00 -> third argument (%34)
**	0x00 ->      -||-
**	0x00 ->      -||-
**	0x22 ->      -||-
**
**	Resulting bytes in order: 0x0b   0x78   0x02   0x00 0x17   0x00 0x00 0x00 0x22
**	
**
**
**	All the operations and their properties in order:
**	1. Name of the operation
**	2. Number of arguments passed
**	3. Types of arguments passed
**	4. 'opcode' or instruction code which is the ordinal number (1-16)
**	5. The 'cost' of the operation in cycles
**	6. Short description of what the operation does
**	7. Indicates if there is or isn't coding byte before arguments
**	8. 
*/

typedef struct	s_op
{
	const char	name[6];
	const int	nbr_arg;
	const int	arg_type[3];
	const int	ord_nbr;
	const int	cost;
	const char	desc[37];
	const int	is_cd_byte;
	const int	nbr2;
}				t_op;


t_op    op_tab[17] =
{
	{
		"live",
		1,
		{T_DIR},
		1,
		10,
		"alive",
		0,
		0
	},
	{
		"ld",
		2,
		{T_DIR | T_IND, T_REG},
		2,
		5,
		"load",
		1,
		0
	},
	{
		"st",
		2,
		{T_REG, T_IND | T_REG},
		3,
		5,
		"store",
		1,
		0
	},
	{
		"add",
		3,
		{T_REG, T_REG, T_REG},
		4,
		10,
		"addition",
		1,
		0
	},
	{
		"sub",
		3,
		{T_REG, T_REG, T_REG},
		5,
		10,
		"soustraction",
		1,
		0
	},
	{
		"and",
		3,
		{T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6,
		6,
		"et (and  r1, r2, r3   r1&r2 -> r3",
		1,
		0
	},
	{
		"or",
		3,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7,
		6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3",
		1,
		0
	},
	{
		"xor",
		3,
		{T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		8,
		6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3",
		1,
		0
	},
	{
		"zjmp",
		1,
		{T_DIR},
		9,
		20,
		"jump if zero",
		0,
		1
	},
	{
		"ldi",
		3,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		10,
		25,
		"load index",
		1,
		1
	},
	{
		"sti",
		3,
		{T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		11,
		25,
		"store index",
		1,
		1
	},
	{
		"fork",
		1,
		{T_DIR},
		12,
		800,
		"fork",
		0,
		1
	},
	{
		"lld",
		2,
		{T_DIR | T_IND, T_REG},
		13,
		10,
		"long load",
		1,
		0
	},
	{
		"lldi",
		3,
		{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		14,
		50,
		"long load index",
		1,
		1
	},
	{
		"lfork",
		1,
		{T_DIR},
		15,
		1000,
		"long fork",
		0,
		1
	},
	{
		"aff",
		1,
		{T_REG},
		16,
		2,
		"aff",
		1,
		0
	},
	{
		0,
		0,
		{0},
		0,
		0,
		0,
		0,
		0
	}
};