const { describe } = require('yargs');
const { validatePassword } = require('./passwordValidator');

describe('Password Validator', () => {
    test("Le mot de passe donné contient au moins 8 caractères.", () => {
        const passwordTest = "1234567";
        exportAllDeclaration(validatePassword(passwordTest)).toBe(true);
    });
});