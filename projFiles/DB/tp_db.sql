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
('УВТ-10В', 'Информатика и вычислительная техника'),
('АВТ-10', 'Автоматика и вычислительная техника'),
('ИС-29', 'Информационные системы и технологии'),
('ПКС-10', 'Программирование в компьютерных системах'),
('ПМФ-10', 'Прикладная математика и физика'),
('ЦТ-29', 'Цифровые технологии'),
('ЯРФ-47', 'Ядерная физика'),
('ВЧ-21', 'Вычислительная математематика');

insert into "user" (sFirstName, sLastName, sThirdName, dblAverageDisciplineScore, idGroup) values 
('Иванов', 'Иван', 'Иванович', 4.95, 1),
('Петров', 'Петр', 'Петрович', 4.78, 1),
('Сидоров', 'Герман', 'Апельсинович', 4.99, 1),
('Алексеев', 'Илья ', 'Константинович', 4.4, 2),
('Алешин', 'Тимофей', 'Даниилович', 4.93, 2),
('Бородина', 'Алина', 'Данииловна', 4.39, 2),
('Гаврилова', 'Милана ', 'Савельевна', 4.49, 3),
('Дорофеева', 'Виктория', 'Александровна', 4.22, 3),
('Дубровин', 'Марк', 'Андреевич', 4.34, 3),
('Ефимова', 'Кристина ', 'Глебовна', 4.49, 4),
('Иванова', 'Елизавета', 'Фёдоровна', 4.39, 4),
('Козлов', 'Георгий', 'Александрович', 4.78, 4),
('Макарова', 'София', 'Всеволодовна', 4.49, 5),
('Максимов', 'Максим', 'Кириллович', 4.84, 5),
('Нестерова', 'Варвара', 'Вячеславовна', 4.74, 5),
('Осипов', 'Марк', 'Ярославович', 4.3, 6),
('Павлов', 'Герман', 'Лукич', 4.83, 6),
('Панина', 'София', 'Максимовна', 4.87, 6);

insert into "object" (sName, sDescription) values
('Вычислительная математика', 'Курс для ВТ'),
('Доп. главы мат. анализа', 'Курс АВТ-29'),
('Инженерная и компьютерная графика', 'ВТ-10'),
('Программирование', 'Общий курс'),
('Системное ПО', 'Общий курс'),
('Математическая логика и теория алгоритмов', 'Общий курс'),
('Базы данных', 'Общий курс'),
('Мультипроцессорные системы', 'Общий курс'),
('Психология труда', 'Общий курс'),
('Экономика', 'Общий курс'),
('Практикум по физике', 'Общий курс'),
('Уравнения математической физики', 'Общий курс'),
('Теоретическая механика', 'Общий курс');

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
(1, 1, '02.04.2021', 4),
(1, 2, '08.04.2021', 5),
(1, 3, '10.04.2021', 4),
(1, 4, '15.04.2021', 4),
(1, 5, '19.04.2021', 3);

insert into userObject(idUser, idObject, dMarkDate, nMarkValue) values
(2, 2, '02.04.2021', 3),
(2, 1, '06.04.2021', 5),
(2, 3, '10.04.2021', 4),
(2, 4, '12.04.2021', 5),
(2, 1, '13.04.2021', 4),
(2, 9, '15.04.2021', 5),
(2, 8, '17.04.2021', 4);

insert into userObject(idUser, idObject, dMarkDate, nMarkValue) values
(3, 1, '02.04.2021', 3),
(3, 1, '06.04.2021', 5),
(3, 1, '10.04.2021', 4),
(3, 3, '12.04.2021', 5),
(3, 3, '13.04.2021', 4),
(3, 4, '15.04.2021', 5),
(3, 7, '17.04.2021', 4);

insert into userObject(idUser, idObject, dMarkDate, nMarkValue) values
(4, 8, '05.04.2021', 4),
(4, 1, '06.04.2021', 3),
(4, 4, '10.04.2021', 5),
(4, 7, '12.04.2021', 3),
(4, 5, '13.04.2021', 5),
(4, 6, '15.04.2021', 4),
(4, 2, '17.04.2021', 5);

insert into userObject(idUser, idObject, dMarkDate, nMarkValue) values
(5, 1, '02.04.2021', 4),
(5, 1, '06.04.2021', 3),
(5, 3, '10.04.2021', 5),
(5, 2, '12.04.2021', 5),
(5, 4, '13.04.2021', 5),
(5, 2, '15.04.2021', 4),
(5, 1, '17.04.2021', 5);

insert into userObject(idUser, idObject, dMarkDate, nMarkValue) values
(6, 1, '02.04.2021', 4),
(6, 2, '06.04.2021', 3),
(6, 3, '10.04.2021', 5),
(6, 4, '12.04.2021', 5),
(6, 5, '13.04.2021', 5),
(6, 6, '15.04.2021', 4),
(6, 7, '17.04.2021', 5),
(6, 6, '03.04.2021', 5),
(6, 7, '11.04.2021', 4);

insert into userObject(idUser, idObject, dMarkDate, nMarkValue) values
(7, 4, '03.04.2021', 4),
(7, 2, '05.04.2021', 3),
(7, 1, '08.04.2021', 5),
(7, 4, '10.04.2021', 5),
(7, 3, '11.04.2021', 5),
(7, 2, '16.04.2021', 4),
(7, 3, '20.04.2021', 5),
(7, 4, '22.04.2021', 5),
(7, 6, '23.04.2021', 4);

