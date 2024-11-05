const getRandomIndex = () => Math.floor(Math.random() * 2);

const a = ["foo", "bar"][getRandomIndex()];
const b = [1, 2][getRandomIndex()];
const c = [{ path: "/foo" }, { path: "/bar" }][getRandomIndex()];
