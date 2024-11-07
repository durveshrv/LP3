// SPDX-License-Identifier: MIT  // License identifier, required for open-source projects (MIT license here)
pragma solidity ^0.8.0;          // Version declaration for the Solidity compiler, ensuring compatibility with version 0.8.0 or later

contract BankAccount {           // Define a contract named 'BankAccount'
    
    // State variables
    address public owner;        // Declare a public variable 'owner' of type 'address', stores the owner's Ethereum address
    uint public balance;          // Declare a public variable 'balance' of type 'uint' to store the bank account balance

    // Constructor
    constructor() {               // Constructor function, which runs once when the contract is deployed
        owner = msg.sender;       // Set the 'owner' to the address that deployed the contract (msg.sender)
    }

    // Functions
    function deposit(uint amount) public {    // 'deposit' function to add funds to the balance (amount is passed as parameter)
        balance += amount;                    // Add the 'amount' to the current balance
    }

    function withdraw(uint amount) public {  // 'withdraw' function to remove funds from the balance (amount is passed as parameter)
        require(balance >= amount, "Insufficient balance"); // Ensure the account has enough balance before proceeding, if not, throw error
        balance -= amount;                   // Subtract the 'amount' from the current balance
    }

    function getBalance() public view returns (uint) {   // 'getBalance' function to check the current balance
        return balance;                                  // Return the current balance
    }
}
