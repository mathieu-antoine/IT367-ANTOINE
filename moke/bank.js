const bankDAO = require("./bankDAO.js")

function getBalance(accountID){
    bankDAO.retrieveBalance(accountID);
}
const bank = {getBalance}
module.exports = bank;