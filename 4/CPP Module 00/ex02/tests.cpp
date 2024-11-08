// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

  /* 생성자
      [19920104_091532] index:0;amount:42;created
      [19920104_091532] index:1;amount:54;created
      [19920104_091532] index:2;amount:957;created
      [19920104_091532] index:3;amount:432;created
      [19920104_091532] index:4;amount:1234;created
      [19920104_091532] index:5;amount:0;created
      [19920104_091532] index:6;amount:754;created
      [19920104_091532] index:7;amount:16576;created
  */
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

  /*
      [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
  */
	Account::displayAccountsInfos();
  
  /*
      [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
      [19920104_091532] index:1;amount:54;deposits:0;withdrawals:0
      [19920104_091532] index:2;amount:957;deposits:0;withdrawals:0
      [19920104_091532] index:3;amount:432;deposits:0;withdrawals:0
      [19920104_091532] index:4;amount:1234;deposits:0;withdrawals:0
      [19920104_091532] index:5;amount:0;deposits:0;withdrawals:0
      [19920104_091532] index:6;amount:754;deposits:0;withdrawals:0
      [19920104_091532] index:7;amount:16576;deposits:0;withdrawals:0
  */
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

  /*
      [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
      [19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
      [19920104_091532] index:2;p_amount:957;deposit:564;amount:1521;nb_deposits:1
      [19920104_091532] index:3;p_amount:432;deposit:2;amount:434;nb_deposits:1
      [19920104_091532] index:4;p_amount:1234;deposit:87;amount:1321;nb_deposits:1
      [19920104_091532] index:5;p_amount:0;deposit:23;amount:23;nb_deposits:1
      [19920104_091532] index:6;p_amount:754;deposit:9;amount:763;nb_deposits:1
      [19920104_091532] index:7;p_amount:16576;deposit:20;amount:16596;nb_deposits:1
  */
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

  /*
      [19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
  */
	Account::displayAccountsInfos();

  /*
      [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
      [19920104_091532] index:1;amount:819;deposits:1;withdrawals:0
      [19920104_091532] index:2;amount:1521;deposits:1;withdrawals:0
      [19920104_091532] index:3;amount:434;deposits:1;withdrawals:0
      [19920104_091532] index:4;amount:1321;deposits:1;withdrawals:0
      [19920104_091532] index:5;amount:23;deposits:1;withdrawals:0
      [19920104_091532] index:6;amount:763;deposits:1;withdrawals:0
      [19920104_091532] index:7;amount:16596;deposits:1;withdrawals:0
  */
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

  /*
      [19920104_091532] index:0;p_amount:47;withdrawal:refused
      [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
      [19920104_091532] index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1
      [19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
      [19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
      [19920104_091532] index:5;p_amount:23;withdrawal:refused
      [19920104_091532] index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
      [19920104_091532] index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1
  */
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

  /*
      [19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
  */
	Account::displayAccountsInfos();

  /*
      [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
      [19920104_091532] index:1;amount:785;deposits:1;withdrawals:1
      [19920104_091532] index:2;amount:864;deposits:1;withdrawals:1
      [19920104_091532] index:3;amount:430;deposits:1;withdrawals:1
      [19920104_091532] index:4;amount:1245;deposits:1;withdrawals:1
      [19920104_091532] index:5;amount:23;deposits:1;withdrawals:0
      [19920104_091532] index:6;amount:106;deposits:1;withdrawals:1
      [19920104_091532] index:7;amount:8942;deposits:1;withdrawals:1
  */
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

  /* 소멸자
      [19920104_091532] index:0;amount:47;closed
      [19920104_091532] index:1;amount:785;closed
      [19920104_091532] index:2;amount:864;closed
      [19920104_091532] index:3;amount:430;closed
      [19920104_091532] index:4;amount:1245;closed
      [19920104_091532] index:5;amount:23;closed
      [19920104_091532] index:6;amount:106;closed
      [19920104_091532] index:7;amount:8942;closed
  */
	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
