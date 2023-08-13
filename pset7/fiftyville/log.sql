-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 and street = 'Chamberlin Street';

.schema courthouse_security_logs

SELECT transcript FROM interviews WHERE day = 28 AND year = 2020 and month = 7;

SELECT name FROM people 
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE day = '28' AND  month = '7' and year = '2020' and hour = '10' and minute >= '15' and minute < '30' and activity = 'exit';

##names of Suspects.{Patrick
Ernest
Amber
Danielle
Roger
Elizabeth
Russell
Evelyn}

SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE day = '28' AND  month = '7' and year = '2020' and transaction_type = 'withdraw' and atm_location = 'Fifer Street';
##names of Suspects{Ernest
Russell
Roy
Bobby
Elizabeth
Danielle
Madison
Victoria}

#Both cases The Name of Suspects{Danielle.Russell.Elizabeth.Ernest}

SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE flight_id = (SELECT id FROM flights WHERE day = '29' AND month = '7' and year = '2020' ORDER BY hour,minute LIMIT 1);

Suspects{Doris
Roger
Ernest
Edward
Evelyn
Madison
Bobby
Danielle}

now The THIEF is Danielle or Ernest

SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number 
WHERE day = '28' AND month = '7' and year = '2020' and duration < '60'

in this case The THIEF is:Ernest

SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE day = '29' AND month = '7' and year = '2020' ORDER BY hour,minute LIMIT 1);
London

in this case The thief ESCAPED TO:London

SELECT name FROM people 
JOIN phone_calls ON phone_calls.receiver = people.phone_number 
WHERE day = '28' AND  month = '7' and year = '2020' and duration < '60' and caller = (SELECT phone_number FROM people WHERE name = 'Ernest');
Berthold
in this case The ACCOMPLICE is:Berthold


