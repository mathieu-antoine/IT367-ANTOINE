const bankDAO = require("./bankDAO.js");
const bank = require("./bank.js");

test ("Should transmit parameter accountID", () => {
    const spy = jest.spyOn(bankDAO, "retrieveBalance");
    spy.mockReturnValue(null);
    bank.getBalance(123);
    expect(spy).toHaveBeenCalled(123);
});