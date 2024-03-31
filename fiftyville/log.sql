-- Keep a log of any SQL queries you execute as you solve the mystery.
 SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND year = 2021 AND street = 'Humphrey Street';

SELECT transcript FROM interviews WHERE month = 7 AND day = 28 AND year = 2021 AND transcript LIKE "%bakery%";


SELECT bakery_security_logs.activity,bakery_security_logs.license_plate,people.name  FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.month = 7 AND bakery_security_logs.day = 28
AND bakery_security_logs.year = 2021 AND bakery_security_logs.hour = 10 AND minute >= 15 AND minute <= 25;


SELECT people.name,atm_transactions.transaction_type FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE month = 7 AND day = 28 AND year = 2021
AND atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw";


UPDATE phone_calls
SET caller_name = people.name
FROM people
WHERE phone_calls.caller = people.phone_number;


UPDATE phone_calls
SET receiver_name = people.name
FROM people
WHERE phone_calls.receiver = people.phone_number;


SELECT caller,caller_name, receiver , receiver_name FROM phone_calls
WHERE month = 7 AND day = 28 AND year = 2021
AND duration < 60;


SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = (
    SELECT id FROM flights
    WHERE month = 7 AND day = 29 AND year = 2021
    AND origin_airport_id = (
        SELECT id FROM airports WHERE CITY = "Fiftyville")
    ORDER BY hour ASC
    LIMIT 1);


SELECT city FROM airports
WHERE id = (SELECT destination_airport_id FROM flights
WHERE  month = 7 AND day = 29 AND year = 2021
AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY hour, minute
LIMIT 1);


SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;



