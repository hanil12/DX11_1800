USE BaseballData;
-- FROM table
-- WHERE (조건)
-- SELECT (속성)
-- OREDER BY

-- * : all

SELECT lahmanID as lahmanKey, playerID as ID, birthYear, birthMonth
FROM players
WHERE birthYear = 1945 OR birthMonth = 10

SELECT lahmanID, deathYear
FROM players
WHERE deathYear IS NOT NULL

-- playres에서 New로하는 도시에서 태어난 사람들을 뽑아주세요
-- '문자열%'... 문자열 + 뒤에 아무거나
SELECT *
FROM players
WHERE birthCity LIKE 'New%'

-- playres에서 birthCity가 New + 뒤에 다섯글자 오는거 뽑아주세요
-- '문자열_' -> 문자열+_ 개수
SELECT *
FROM players
WHERE birthCity LIKE 'New_____'

-- players에서 일찍 돌아가신 분들의 lahmanID, deathYear을 뽑아주세요, 단 deathYear 순으로 뽑아주세요.
SELECT lahmanID, deathYear
FROM players
WHERE deathYear IS NOT NULL
ORDER BY deathYear ASC

-- players에서 일찍 돌아가신 분들의 lahmanID, deathYear, deathMonth을 뽑아주세요, 단 deathYear, deathMonth 역순으로 뽑아주세요.
SELECT lahmanID, deathYear, deathMonth
FROM players
WHERE deathYear IS NOT NULL
ORDER BY deathYear DESC, deathMonth DESC

-- players에서 birthYear가 1950인 분들의 명수
SELECT COUNT(lahmanID)
FROM players
WHERE birthYear = 1950

--  player에서 birthYear의 평균을 구해주세요
SELECT AVG(birthYear) as 평균생년
FROM players
WHERE birthYear IS NOT NULL

-- player에서 살아있는 분들의 나이의 평균을 뽑아주세요
SELECT AVG(2023 - birthYear) as 평균나이
FROM players
WHERE deathYear IS NULL AND birthYear IS NOT NULL

-- player에서 살아있는 분들의 최소령의 나이를 뽑아주세요
SELECT MIN(2023 - birthYear) as 평균나이
FROM players
WHERE deathYear IS NULL AND birthYear IS NOT NULL

-- players에서 모든 플레이어의 데뷔날짜
SELECT YEAR(CONVERT(DATETIME,debut)) as debutDate
FROM players
WHERE debut IS NOT NULL
ORDER BY debutDate