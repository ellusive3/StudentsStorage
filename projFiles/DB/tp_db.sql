--drop table if exists state cascade;
--drop table if exists city cascade;
--drop table if exists object cascade;
--drop table if exists theme cascade;
--drop table if exists "user" cascade;
--drop table if exists event;
--drop table if exists link;
--drop table if exists "group";
--drop table if exists userCity;
--drop table if exists userObject;

create table state
(
    id serial,
    sname varchar(45) not null,
    primary key(id)
);

create table city
(
    id serial,
    sName varchar(45),
    idState integer,
    rating double precision,
    sfacts varchar(1024),
    dblLatitude double precision,
    dblLongtitude double precision,
    primary key(id),
    foreign key (idState) references state(id)
);

create table event
(
    id serial,
    ddate date,
    idCity integer,
    ttime time,
    primary key(id),
    foreign key(idCity) references city(id)
);


create table object
(
    id serial,
    sName varchar(45),
    sDescription varchar(45),
    primary key(id)
);

create table theme
(
    id serial,
    idObject integer,
    sName varchar(200),
    primary key(id),
    foreign key(idObject) references object(id)
);

create table link
(
    id serial,
    idTheme integer,
    sLink varchar(512),
    primary key(id),
    foreign key(idTheme) references theme(id)
);

create table "group"
(
    id serial,
    sName varchar(45),
    sDescription varchar(45),
    primary key(id)
);

create table "user"
(
    id serial,
    sFirstName varchar(45),
    sLastName varchar(45),
    sThirdName varchar(45),
    dblAverageDisciplineScore double precision,
    idGroup integer,
    primary key(id),
    foreign key(idGroup) references "group"(id)
);

create table userCity
(
    idUser integer,
    idCity integer,
    dblRateValue double precision,
    dVisitDate date,
    foreign key(idUser) references "user"(id),
    foreign key(idCity) references "city"(id)
);

create table userObject
(
    idUser integer,
    idObject integer,
    dMarkDate date,
    nMarkValue integer,
    foreign key(idUser) references "user"(id),
    foreign key(idObject) references "object"(id)
);


-- Заполняем таблицу тестовыми данными -- 
insert into "group" (sName, sDescription) values
('УТМ-10В', 'Технология машиностроения'),
('УВТ-10В', 'Информатика и вычислительная техника');

insert into "user" (sFirstName, sLastName, sThirdName, dblAverageDisciplineScore, idGroup) values 
('Иванов', 'Иван', 'Иванович', 4.95, 1),
('Петров', 'Петр', 'Петрович', 4.78, 2),
('Сидоров', 'Герман', 'Апельсинович', 4.99, 2);

insert into "object" (sName, sDescription) values
('Вычислительная математика', 'Курс для ВТ'),
('Культорология', 'Общий курс');

insert into theme (idObject, sName) values
(1, 'Решение задач с использованием численных методов'),
(2, 'Культурология как самосознание культуры');

insert into state (sName) values
('Нижегородская область'),
('Московская область'),
('Владимирская область');

insert into city (sName, idState, rating, sFacts) values
('Саров', 1, 4.55, 'В Сарове находится 9 памятников природы: Саровские серебряные ключи, Ближняя и Дальняя пустынки, Эрзянское священное урочище Кереметь[uk], Заливной луг в пойме реки Сатиса, монастырский Шелокшанский прудок, монастырское урочище Филипповка и Сысовский кордон, монастырские пруды Протяжка и Варламовский.'),
('Москва', 2, 4.49, 'Самое красивое в мире метро. Самая большая в Европе библиотека. Город, который никогда не спит.'),
('Владимир', 3, 4.6, 'Князь Владимир Мономах основал город, названный в его честь, примерно в 1100 году. Согласно еще одной распространенной версии, город значительно древнее, и был заложен ещё в 990 году.');

insert into "event" (ddate, idCity, ttime) values
('25.03.2021', 1, '14:30'),
('29.03.2021', 2, '15:15'),
('02.04.2021', 3, '18:45');

insert into userCity (idUser, idCity, dblRateValue, dVisitDate) values
(1, 1, 4.67, '01.03.2021'),
(2, 2, 4.79, '05.02.2021');

insert into userObject(idUser, idObject, dMarkDate, nMarkValue) values
(1, 1, '29.03.2021', 4),
(1, 2, '01.04.2021', 5)

