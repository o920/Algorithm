-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME, IF(SEX_UPON_INTAKE LIKE 'Intact%', "X","O")
FROM ANIMAL_INS
ORDER BY ANIMAL_ID
