const bankDAO = {
    retrieveBalance: function (accountId) {
        console.log(`Retrieve balance for account: ${accountId}`);
        return 100;
    }
};

module.exports = bankDAO;