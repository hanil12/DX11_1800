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

-- 중복제거
-- players에서 중복없이 birthCity를 출력해주세요
SELECT COUNT(DISTINCT birthCity)
FROM players

-- players에서 평균 몸무게를 출력할건데, (단 몸무게 정보가 NULL인 얘들은 0으로 처리)
SELECT AVG(
CASE 
WHEN weight IS NULL THEN 0 
ELSE weight END)
FROM players


SELECT *
FROM batting
--1) 보스턴 소속 선수들의 정보들만 모두 출력해주세요
SELECT *
FROM batting
WHERE teamID = 'BOS'

--2) 보스턴 소속 선수들의 수는 몇명입니까?(단 중복은 제거)
SELECT COUNT(DISTINCT playerID)
FROM batting
WHERE teamID = 'BOS'
--3) 보스턴 팀이 2004년도에 친 홈런 개수
SELECT SUM(HR)
FROM batting
WHERE teamID = 'BOS' AND yearID = 2004
--4) 보스턴 팀 소속으로 단일 년도 최다 홈런을 친 친사람의 정보
SELECT TOP(1) *
FROM batting
WHERE teamID = 'BOS'
ORDER BY HR DESC

-- playerID는 외래키라고 한다.
SELECT nameFirst, nameLast
FROM players
WHERE playerID = 
(SELECT TOP(1) playerID
FROM batting
WHERE teamID = 'BOS'
ORDER BY HR DESC)

-- FROM			책상에서
-- WHERE		공을
-- GROUP BY		색상별로 분류해서
-- HAVING		분류한 중에 빨강공은 빼고
-- SELECT		갖고와서
-- OREDER BY	크기 별로 나열해주세요

SELECT *
FROM batting

-- 팀들의 홈런 개수를 보여주세요
SELECT teamID, yearID ,SUM(HR) as homeRUN
FROM batting
GROUP BY teamID, yearID
HAVING SUM(HR) >= 200
ORDER BY homeRUN DESC

SELECT SUM(HR)
FROM batting
WHERE teamID = 'HOU'

-- 두 테이블의 결합
-- JOIN

SELECT *
FROM players

SELECT *
FROM salaries

SELECT *
FROM players
	INNER JOIN salaries
	ON players.playerID = salaries.playerID


-- salaries 정보가 있고, players에는 정보가 없는 얘들의 playerID를 출력해주세요
SELECT *
FROM players
	RIGHT JOIN salaries
	ON players.playerID = salaries.playerID

SELECT DISTINCT salaries.playerID
FROM players
	RIGHT JOIN salaries
	ON players.playerID = salaries.playerID
WHERE players.playerID IS NULL