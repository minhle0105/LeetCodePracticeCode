package com.minhle.practiceleetcode;

public class SimpleBankSystem {
    private final long[] accountBalances;
    private final int n;
    public SimpleBankSystem(long[] balance) {
        this.accountBalances = balance;
        this.n = this.accountBalances.length;
    }

    public boolean transfer(int account1, int account2, long money) {
        boolean account1IsValid = account1 >= 1 && account1 <= n;
        boolean account2IsValid = account2 >= 1 && account2 <= n;
        if ((!account1IsValid) | (!account2IsValid)) {
            return false;
        }
        boolean account1HasEnoughBalance = this.accountBalances[account1 - 1] >= money;
        if (account1HasEnoughBalance) {
            this.accountBalances[account1 - 1] -= money;
            this.accountBalances[account2 - 1] += money;
            return true;
        }
        return false;

    }

    public boolean deposit(int account, long money) {
        boolean accountNumberIsValid = account >= 1 && account <= n;
        if (accountNumberIsValid) {
            this.accountBalances[account - 1] += money;
            return true;
        }
        return false;
    }

    public boolean withdraw(int account, long money) {
        boolean accountNumberIsValid = account >= 1 && account <= n;
        if (accountNumberIsValid) {
            long amountBefore = this.accountBalances[account - 1];
            if (amountBefore < money) {
                return false;
            }
            this.accountBalances[account - 1] -= money;
            return true;
        }
        return false;
    }
}
