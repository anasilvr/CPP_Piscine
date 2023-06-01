/*
TODO:

[ ] Create a program which outputs the value of a certain amount of bitcoin on
a certain date. [ ] Use a database in csv format which will represent bitcoin
price over time. [ ] The program will take as input a second database, storing
the different prices/dates to evaluate.

Your program must respect these rules:
    [x] The program name is btc.
    [ ] Your program must take a file as argument.
        [ ] Each line in this file must use the following format: "date | value"
		[ ] A valid date will always be in the following format: Year-Month-Day
        [ ] A valid value must be either a float or a positive integer
		between 0 and 1000.

[ ] STDOUT: the result of the value multiplied by the exchange rate according
to the date indicated in your database. [ ] If the date used in the input does
not exist in your DB then you must use the closest date contained in your DB [
] Be careful to use the lower date and not the upper one.

[ ] You must use at least one container in your code to validate this (pair?)
[ ] You should handle possible errors with an appropriate error message.
[ ] Validate file permissions
*/