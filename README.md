<h1 align="center">Universal Password Checker</h1>

<p align="center">
  Password checker available in 13 languages
</p>
<br/>

This is a universal password checker available in 13 programming languages that lets you check if the password that is being entered is considered "strong" and also tells you how many steps are left for it to be considered strong, if it's not. 

This problem is derived from [Leetcode](https://leetcode.com), where it is one of the problems with the lowest acceptance (correct solution submitted) rates on the platform, which is why I took the challenge to complete it in a dozen languages.

### Why "Universal"?
The reason I called it a universal password checker is because it is available in 13 of the most popular programming languages. Those are:

- C
- C#
- C++
- GO
- Java
- JavaScript
- Kotlin
- Perl
- PHP
- Python
- Rust
- Swift
- TypeScript

### What does "strong" mean?
Any given password is considered strong if all of the following parameter are fulfilled:

- the password does atleast contain 6 characters
- the password does not exceed 20 characters
- the password has atleast one lower case letter
- the password has atleast one upper case letter
- the password has atleast one number
- the password does not have the same letter any more than 2 times in a row
