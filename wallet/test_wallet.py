#test_wallet.py

import pytest
from wallet import Wallet, InsufficientAmount



@pytest.fixture
def empty_wallet():
	'''Returns a wallet instance with zero balance'''
	return Wallet()

@pytest.fixture
def my_wallet():
	"""Same like an empty wallet"""
	return Wallet()

@pytest.mark.parametrize("earned, spent, expected",[
	(30, 10, 20),
	 (20, 2, 18)
	 ])

def test_transactions(my_wallet, earned, spent, expected):
	my_wallet.add_cash(earned)
	my_wallet.spend_cash(spent)
	assert my_wallet.balance == expected

@pytest.fixture
def wallet():
	'''Returns a balnce instance of 20'''
	return Wallet(20)

def test_default_initial_amount(empty_wallet):
	assert empty_wallet.balance == 0

def test_setting_initial_amount(wallet):
	assert wallet.balance == 20

def test_wallet_add_cash(wallet):
	wallet.add_cash(80)
	assert wallet.balance == 100

def test_wallet_spend_cash(wallet):
	wallet.spend_cash(10)
	assert wallet.balance == 10

def test_wallet_exception_raise(empty_wallet):
	with pytest.raises(InsufficientAmount):
		empty_wallet.spend_cash(100)


