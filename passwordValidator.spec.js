const isValidPassword = require("./passwordValidator")

test("Passord plsu de 8",()=>{
    const isValid = isValidPassword("12345678");
    expect(isValid).toBe(true);
}
)

test("Passord plsu de 8",()=>{
    const isValid = isValidPassword("1234568");
    expect(isValid).toBe(false);
}
)