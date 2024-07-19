--Using or
select name, population, area from World
where area>=3000000 or population>=25000000;


-- Using Union

-- select name,population,area from World
-- where area>=3000000
-- union
-- select name,population,area from World
-- where population>=25000000;