export function lex_compare(s1, s2) {
    if (s1.length !== s2.length) return -1;
    for (let i = 0; i < s1.length; ++i) {
        if (s1[i] !== s2[i]) return -1;
    }
    return 1;
}

export function power(number, to_power) {
    let result = number;
    for (let i = 1; i < to_power; i++) {
        result *= number;
    }
    return result;
}