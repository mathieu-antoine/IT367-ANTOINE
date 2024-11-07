const bank = require('./bank');
const bankDAO = require('./bankDAO');

test('retrieveBalance est bien appelée mais sans exécution', () => {
    const spy = jest.spyOn(bankDAO, 'retrieveBalance').mockImplementation(() => {});
    bankDAO.retrieveBalance();
    expect(spy).toHaveBeenCalled();
    spy.mockRestore();
});

test('accountId est bien transmis à retrieveBalance', () => {
    const spy = jest.spyOn(bankDAO, 'retrieveBalance').mockImplementation(() => {});
    bank.getBalance(123);
    expect(spy).toHaveBeenCalledWith(123);
    spy.mockRestore();
});

test('getBalance retourne le solde de retrieveBalance', () => {
    jest.spyOn(bankDAO, 'retrieveBalance').mockReturnValue(1000);
    const balance = bank.getBalance(123);
    expect(balance).toBe(100);
});
