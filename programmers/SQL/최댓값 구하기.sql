-- 코드를 입력하세요
SELECT DATETIME
FROM ANIMAL_INS
ORDER BY DATETIME DESC
LIMIT 1

-- 코드를 입력하세요
SELECT DATETIME
FROM ANIMAL_INS
WHERE DATETIME IN (SELECT MAX(DATETIME) FROM ANIMAL_INS)
