DROP TABLE morekitype;
DROP TABLE moreki;

CREATE TABLE morekitype
(
typeid NUMBER(1),
typename VARCHAR2(10) NOT NULL,
CONSTRAINT pk_typeidfinal PRIMARY KEY(typeid)
);


CREATE TABLE moreki
(
cid VARCHAR2(23) PRIMARY KEY,
fname VARCHAR2(20) NOT NULL,
lname VARCHAR2(20) NOT NULL,
sex CHAR(1) NOT NULL,
dob DATE DEFAULT SYSDATE NOT NULL, 
type NUMBER(1),
CONSTRAINT fk_typeidfinal FOREIGN KEY(type) REFERENCES morekitype(typeid)
);