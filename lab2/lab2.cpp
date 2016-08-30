// Random Number game!
// Ellie Hensley
// 8-25-16
// The computer picks a number and the user has to guess it. 
// If wrong, the computer will output "higher" or "lower" so the user can make an improved guess.
// The user can only guess 10 times for each number.



// 1.) score is set to zero. 
// 2.) numTries is set to 10.
// 3.) Computer picks a random number between 0-9 and sets it to a variable.
// 4.) The computer determines if the round-score is greater than zero.
//      4a.) If it is greater than zero, the computer prompts the user to input a number and proceeds to step 4.
//      4b.) If it is equal to or less than zero, the computer returns to step 2.
// 5.) User inputs a number.
// 6.) Computer compares the user-number with the random number.
//      6a.) If the user-number is less than the random number, the computer outputs "Higher. Guess again!" and decreases numTries by 1 and returns to step 4.
//      6b.) If the user-number is greater than the random number, the computer outputs "Lower. Guess again!" and decreases numTries by 1 and returns to step 4.
//      6c.) If the user-number is the same as the random number, the computer outputs "Correct", increases the score by 10, and returns to step 2.