/*
 * Copyright 2016, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *     * Neither the name of the copyright holder nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * win_getopt.c -- test for windows getopt() implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "unittest.h"

/*
 * long_options -- command line arguments
 */
static const struct option long_options[] = {
	{ "arg_a",	no_argument,		0,	'a' },
	{ "arg_b",	no_argument,		0,	'b' },
	{ "arg_c",	no_argument,		0,	'c' },
	{ "arg_d",	no_argument,		0,	'd' },
	{ "arg_e",	no_argument,		0,	'e' },
	{ "arg_f",	no_argument,		0,	'f' },
	{ "arg_g",	no_argument,		0,	'g' },
	{ "arg_h",	no_argument,		0,	'h' },
	{ "arg_A",	required_argument,	0,	'A' },
	{ "arg_B",	required_argument,	0,	'B' },
	{ "arg_C",	required_argument,	0,	'C' },
	{ "arg_D",	required_argument,	0,	'D' },
	{ "arg_E",	required_argument,	0,	'E' },
	{ "arg_F",	required_argument,	0,	'F' },
	{ "arg_G",	required_argument,	0,	'G' },
	{ "arg_H",	required_argument,	0,	'H' },
	{ "arg_1",	optional_argument,	0,	'1' },
	{ "arg_2",	optional_argument,	0,	'2' },
	{ "arg_3",	optional_argument,	0,	'3' },
	{ "arg_4",	optional_argument,	0,	'4' },
	{ "arg_5",	optional_argument,	0,	'5' },
	{ "arg_6",	optional_argument,	0,	'6' },
	{ "arg_7",	optional_argument,	0,	'7' },
	{ "arg_8",	optional_argument,	0,	'8' },
	{ 0,		0,			0,	 0 },
};

int
main(int argc, char *argv[])
{
	int opt;
	int option_index;

	START(argc, argv, "win_getopt");

	while ((opt = getopt_long(argc, argv,
			"abcdefghA:B:C:D:E:F:G::H1::2::3::4::5::6::7::8::",
			long_options, &option_index)) != -1) {
		switch (opt) {
		case '?':
			UT_OUT("unknown argument");
			break;
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
			UT_OUT("arg_%c", opt);
			break;
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
			UT_OUT("arg_%c=%s", opt,
				optarg == NULL ? "null": optarg);
			break;
		}
	}
	while (optind < argc) {
		UT_OUT("%s", argv[optind++]);
	}
	DONE(NULL);
}
