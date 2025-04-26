#pragma once
#include "stdafx.h"

#define N_GRAPHS 31
#define token_size 256

#define GRAPH_string  (7,   \
	FST::NODE(1, FST::RELATION('s', 1)), \
	FST::NODE(1, FST::RELATION('t', 2)), \
	FST::NODE(1, FST::RELATION('r', 3)), \
	FST::NODE(1, FST::RELATION('i', 4)), \
	FST::NODE(1, FST::RELATION('n', 5)), \
	FST::NODE(1, FST::RELATION('g', 6)), \
	FST::NODE())

#define GRAPH_number (7,	\
	FST::NODE(1, FST::RELATION('n', 1)),  \
	FST::NODE(1, FST::RELATION('u', 2)),  \
	FST::NODE(1, FST::RELATION('m', 3)),  \
	FST::NODE(1, FST::RELATION('b', 4)),  \
	FST::NODE(1, FST::RELATION('e', 5)),  \
	FST::NODE(1, FST::RELATION('r', 6)),  \
	FST::NODE())

#define GRAPH_char  (5,   \
	FST::NODE(1, FST::RELATION('c', 1)), \
	FST::NODE(1, FST::RELATION('h', 2)), \
	FST::NODE(1, FST::RELATION('a', 3)), \
	FST::NODE(1, FST::RELATION('r', 4)), \
	FST::NODE())

#define GRAPH_print (6,	\
	FST::NODE(1, FST::RELATION('p', 1)),  \
	FST::NODE(1, FST::RELATION('r', 2)),  \
	FST::NODE(1, FST::RELATION('i', 3)),  \
	FST::NODE(1, FST::RELATION('n', 4)),  \
	FST::NODE(1, FST::RELATION('t', 5)),  \
	FST::NODE())	

#define GRAPH_if  (3,   \
	FST::NODE(1, FST::RELATION('i', 1)),  \
	FST::NODE(1, FST::RELATION('f', 2)),  \
	FST::NODE())	

#define GRAPH_function (9,\
	FST::NODE(1, FST::RELATION('f', 1)),  \
	FST::NODE(1, FST::RELATION('u', 2)),  \
	FST::NODE(1, FST::RELATION('n', 3)),  \
	FST::NODE(1, FST::RELATION('c', 4)),  \
	FST::NODE(1, FST::RELATION('t', 5)),  \
	FST::NODE(1, FST::RELATION('i', 6)),  \
	FST::NODE(1, FST::RELATION('o', 7)),  \
	FST::NODE(1, FST::RELATION('n', 8)),  \
	FST::NODE())

#define GRAPH_main (5,\
	FST::NODE(1, FST::RELATION('m', 1)), \
	FST::NODE(1, FST::RELATION('a', 2)), \
	FST::NODE(1, FST::RELATION('i', 3)), \
	FST::NODE(1, FST::RELATION('n', 4)), \
	FST::NODE())

#define GRAPH_define (7,\
	FST::NODE(1, FST::RELATION('d', 1)),  \
	FST::NODE(1, FST::RELATION('e', 2)),  \
	FST::NODE(1, FST::RELATION('f', 3)),  \
	FST::NODE(1, FST::RELATION('i', 4)),  \
	FST::NODE(1, FST::RELATION('n', 5)),  \
	FST::NODE(1, FST::RELATION('e', 6)),  \
	FST::NODE())

#define GRAPH_return (7,\
	FST::NODE(1, FST::RELATION('r', 1)),  \
	FST::NODE(1, FST::RELATION('e', 2)),  \
	FST::NODE(1, FST::RELATION('t', 3)),  \
	FST::NODE(1, FST::RELATION('u', 4)),  \
	FST::NODE(1, FST::RELATION('r', 5)),  \
	FST::NODE(1, FST::RELATION('n', 6)),  \
	FST::NODE())	

#define GRAPH_cycle (6,\
	FST::NODE(1, FST::RELATION('c', 1)),  \
	FST::NODE(1, FST::RELATION('y', 2)),  \
	FST::NODE(1, FST::RELATION('c', 3)),  \
	FST::NODE(1, FST::RELATION('l', 4)),  \
	FST::NODE(1, FST::RELATION('e', 5)),  \
	FST::NODE())


#define GRAPH_integer_literal (3,\
	FST::NODE(20, \
		FST::RELATION('n', 1), FST::RELATION('1', 1), \
		FST::RELATION('2', 1), FST::RELATION('3', 1), \
		FST::RELATION('4', 1), FST::RELATION('5', 1), \
		FST::RELATION('6', 1), FST::RELATION('7', 1), \
		FST::RELATION('8', 1), FST::RELATION('9', 1), \
		FST::RELATION('1', 2), FST::RELATION('2', 2), \
		FST::RELATION('3', 2), FST::RELATION('4', 2), \
		FST::RELATION('5', 2), FST::RELATION('6', 2), \
		FST::RELATION('7', 2), FST::RELATION('8', 2), \
		FST::RELATION('9', 2), FST::RELATION('0', 2)), \
	FST::NODE(20, \
		FST::RELATION('1', 1), FST::RELATION('2', 1), \
		FST::RELATION('3', 1), FST::RELATION('4', 1), \
		FST::RELATION('5', 1), FST::RELATION('6', 1), \
		FST::RELATION('7', 1), FST::RELATION('8', 1), \
		FST::RELATION('9', 1), FST::RELATION('0', 1), \
		FST::RELATION('1', 2), FST::RELATION('2', 2), \
		FST::RELATION('3', 2), FST::RELATION('4', 2), \
		FST::RELATION('5', 2), FST::RELATION('6', 2), \
		FST::RELATION('7', 2), FST::RELATION('8', 2), \
		FST::RELATION('9', 2), FST::RELATION('0', 2)), \
	FST::NODE())

#define GRAPH_integerx2_literal (4,\
	FST::NODE(2, \
		FST::RELATION('n', 0),FST::RELATION('b', 1)), \
	FST::NODE(4, \
		FST::RELATION('0', 2), FST::RELATION('1', 2), \
		FST::RELATION('0', 3), FST::RELATION('1', 3)), \
	FST::NODE(4, \
		FST::RELATION('0', 2), FST::RELATION('1', 2), \
		FST::RELATION('0', 3), FST::RELATION('1', 3)), \
	FST::NODE())

#define GRAPH_integerx8_literal (4,\
	FST::NODE(2, \
		FST::RELATION('n', 0),FST::RELATION('o', 1)), \
	FST::NODE(16, \
		FST::RELATION('1', 2), FST::RELATION('2', 2), \
		FST::RELATION('3', 2), FST::RELATION('4', 2), \
		FST::RELATION('5', 2), FST::RELATION('6', 2), \
		FST::RELATION('7', 2), FST::RELATION('0', 2), \
		FST::RELATION('1', 3), FST::RELATION('2', 3), \
		FST::RELATION('3', 3), FST::RELATION('4', 3), \
		FST::RELATION('5', 3), FST::RELATION('6', 3), \
		FST::RELATION('7', 3), FST::RELATION('0', 3)), \
	FST::NODE(16, \
		FST::RELATION('1', 2), FST::RELATION('2', 2), \
		FST::RELATION('3', 2), FST::RELATION('4', 2), \
		FST::RELATION('5', 2), FST::RELATION('6', 2), \
		FST::RELATION('7', 2), FST::RELATION('0', 2), \
		FST::RELATION('1', 3), FST::RELATION('2', 3), \
		FST::RELATION('3', 3), FST::RELATION('4', 3), \
		FST::RELATION('5', 3), FST::RELATION('6', 3), \
		FST::RELATION('7', 3), FST::RELATION('0', 3)), \
	FST::NODE())

#define GRAPH_id (3, FST::NODE(54, FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), \
	FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), \
	FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
	FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), \
	FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1), \
	FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
	FST::RELATION('y', 1), FST::RELATION('z', 1), FST::RELATION('_', 2),\
	FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2), \
	FST::RELATION('e', 2), FST::RELATION('f', 2), FST::RELATION('g', 2), FST::RELATION('h', 2), \
	FST::RELATION('i', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2), \
	FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), \
	FST::RELATION('q', 2), FST::RELATION('r', 2), FST::RELATION('s', 2), FST::RELATION('t', 2), \
	FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2), \
	FST::RELATION('y', 2), FST::RELATION('z', 2), FST::RELATION('_', 1)), \
FST::NODE(74, FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), \
	FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), \
	FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
	FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), \
	FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1), \
	FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
	FST::RELATION('y', 1), FST::RELATION('z', 1), FST::RELATION('_', 1), \
	FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), \
	FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), \
	FST::RELATION('8', 1), FST::RELATION('9', 1), \
	FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2), \
	FST::RELATION('e', 2), FST::RELATION('f', 2), FST::RELATION('g', 2), FST::RELATION('h', 2), \
	FST::RELATION('i', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2), \
	FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), \
	FST::RELATION('q', 2), FST::RELATION('r', 2), FST::RELATION('s', 2), FST::RELATION('t', 2), \
	FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2), \
	FST::RELATION('y', 2), FST::RELATION('z', 2), FST::RELATION('_', 2), \
	FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2), \
	FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), \
	FST::RELATION('9', 2), FST::RELATION('0', 2)), \
FST::NODE())


#define GRAPH_string_literal (3, \
	FST::NODE(1, \
		FST::RELATION('"', 1)), \
	FST::NODE(153, \
		FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), \
		FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), \
		FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), \
		FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), \
		FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1), \
		FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), \
		FST::RELATION('y', 1), FST::RELATION('z', 1), \
		\
		FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1), \
		FST::RELATION('E', 1), FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1), \
		FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1), \
		FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), \
		FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1), \
		FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1), \
		FST::RELATION('Y', 1), FST::RELATION('Z', 1), \
		\
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), \
		\
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), \
		FST::RELATION('�', 1), \
		\
		FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), \
		FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), \
		FST::RELATION('8', 1), FST::RELATION('9', 1), \
		\
		FST::RELATION(' ', 1), FST::RELATION(',', 1), FST::RELATION('.', 1), FST::RELATION(';', 1), \
		FST::RELATION('-', 1), FST::RELATION('+', 1), FST::RELATION('*', 1), FST::RELATION('/', 1), \
		FST::RELATION('=', 1), FST::RELATION(':', 1), FST::RELATION(')', 1), FST::RELATION('(', 1), \
		FST::RELATION('}', 1), FST::RELATION('{', 1), FST::RELATION(']', 1), FST::RELATION('[', 1), \
		FST::RELATION('!', 1), FST::RELATION('?', 1), FST::RELATION('#', 1), FST::RELATION('&', 1), \
		FST::RELATION('>', 1), FST::RELATION('<', 1), FST::RELATION('[', 1), FST::RELATION(']', 1), \
		FST::RELATION('"', 2)), \
	FST::NODE())

#define GRAPH_char_literal (4, \
    FST::NODE(1, FST::RELATION('\'', 1)), \
    FST::NODE(87, \
        FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2), \
        FST::RELATION('e', 2), FST::RELATION('f', 2), FST::RELATION('g', 2), FST::RELATION('h', 2), \
        FST::RELATION('i', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2), \
        FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), \
        FST::RELATION('q', 2), FST::RELATION('r', 2), FST::RELATION('s', 2), FST::RELATION('t', 2), \
        FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2), \
        FST::RELATION('y', 2), FST::RELATION('z', 2), \
        FST::RELATION('A', 2), FST::RELATION('B', 2), FST::RELATION('C', 2), FST::RELATION('D', 2), \
        FST::RELATION('E', 2), FST::RELATION('F', 2), FST::RELATION('G', 2), FST::RELATION('H', 2), \
        FST::RELATION('I', 2), FST::RELATION('J', 2), FST::RELATION('K', 2), FST::RELATION('L', 2), \
        FST::RELATION('M', 2), FST::RELATION('N', 2), FST::RELATION('O', 2), FST::RELATION('P', 2), \
        FST::RELATION('Q', 2), FST::RELATION('R', 2), FST::RELATION('S', 2), FST::RELATION('T', 2), \
        FST::RELATION('U', 2), FST::RELATION('V', 2), FST::RELATION('W', 2), FST::RELATION('X', 2), \
        FST::RELATION('Y', 2), FST::RELATION('Z', 2), \
		\
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), \
		\
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), \
		FST::RELATION('�', 2), \
		\
        FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), \
        FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2), \
        FST::RELATION('8', 2), FST::RELATION('9', 2), \
        FST::RELATION(' ', 2), FST::RELATION(',', 2), FST::RELATION('.', 2), FST::RELATION(';', 2), \
        FST::RELATION('-', 2), FST::RELATION('+', 2), FST::RELATION('*', 2), FST::RELATION('/', 2), \
        FST::RELATION('=', 2), FST::RELATION(':', 2), FST::RELATION(')', 2), FST::RELATION('(', 2), \
        FST::RELATION('}', 2), FST::RELATION('{', 2), FST::RELATION(']', 2), FST::RELATION('[', 2), \
        FST::RELATION('!', 2), FST::RELATION('?', 2), FST::RELATION('#', 2), FST::RELATION('&', 2), \
        FST::RELATION('>', 2), FST::RELATION('<', 2)), \
    FST::NODE(1, FST::RELATION('\'', 3)), \
	FST::NODE())

#define GRAPH_SEMICOLON (2, \
	FST::NODE(1, FST::RELATION(';', 1)), \
	FST::NODE())

#define GRAPH_COMMA (2, \
	FST::NODE(1, FST::RELATION(',', 1)), \
	FST::NODE())

#define GRAPH_LEFTBRCE (2, \
	FST::NODE(1, FST::RELATION('{', 1)), \
	FST::NODE())

#define GRAPH_BRACELET (2, \
	FST::NODE(1, FST::RELATION(' }', 1)), \
	FST::NODE())

#define GRAPH_LEFTHESIS (2, \
	FST::NODE(1, FST::RELATION('(', 1)), \
	FST::NODE())

#define GRAPH_RIGHTHESIS (2, \
	FST::NODE(1, FST::RELATION(')', 1)), \
	FST::NODE())

#define GRAPH_BIGGEROREQUAL (3, \
	FST::NODE(1, FST::RELATION('>', 1)), \
	FST::NODE(1, FST::RELATION('=', 2)), \
	FST::NODE())

#define GRAPH_NOTEQUAL (3, \
	FST::NODE(1, FST::RELATION('!', 1)), \
	FST::NODE(1, FST::RELATION('=', 2)), \
	FST::NODE())

#define GRAPH_LOWER (2, \
	FST::NODE(1, FST::RELATION('<', 1)), \
	FST::NODE())

#define GRAPH_LOWEROREQUAL (3, \
	FST::NODE(1, FST::RELATION('<', 1)), \
	FST::NODE(1, FST::RELATION('=', 2)), \
	FST::NODE())

#define GRAPH_DOUBLEEQUAL (3, \
	FST::NODE(1, FST::RELATION('=', 1)), \
	FST::NODE(1, FST::RELATION('=', 2)), \
	FST::NODE())

#define GRAPH_BIGGER (2, \
	FST::NODE(1, FST::RELATION('>', 1)), \
	FST::NODE())

#define GRAPH_EQUAL (2, \
	FST::NODE(1, FST::RELATION('=', 1)), \
	FST::NODE())

#define GRAPH_PLUS (2, \
	FST::NODE(1, FST::RELATION('+', 1)), \
	FST::NODE())

#define GRAPH_MINUS (2, \
	FST::NODE(1, FST::RELATION('-', 1)), \
	FST::NODE())



namespace LA
{
	struct Machines
	{
		char lexema;
		FST::FST machine;
	};

	struct Tables
	{
		LT::LexTable LexTable;
		IT::IdTable  idTable;
	};

	struct Info
	{
		IT::IDDATATYPE iddatatype = IT::IDDATATYPE::NODEF;
		IT::IDTYPE idtype = IT::IDTYPE::V;
		char* prefix = new char(256);
		bool flagInFunc = false;
		bool flagParam = false;
		bool flagFunc = false;
		bool flagMain = false;
		bool flagInMain = false;
		bool flagIf = false;
		bool flagInIf = false;
		bool flagCycle = false;
		bool flagInCycle = false;
		bool flagOperator = false;
		bool flagInPrint = false;
		stack<string> defScopes;
		std::vector<const char*> functions;
	};

	void InTables(LA::Tables& tables, int posword, int line, char* word, LA::Info& info);

	Tables Lex_analyz(In::IN in);

	void GetInfo(LA::Info& info, char* word);

	bool CheckInVector(std::vector<const char*> vector, const char* word);
}