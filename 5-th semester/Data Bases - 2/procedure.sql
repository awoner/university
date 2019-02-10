Use ExampleDB
Go 


CREATE PROCEDURE MyProcedure AS

DECLARE @FNAME VARCHAR(10)
DECLARE @SNAME VARCHAR(10)
DECLARE @FACNAME VARCHAR(10)

DECLARE @CURSOR CURSOR

SET @CURSOR  = CURSOR SCROLL
FOR
SELECT FirstName, SecondName, FacultyName
  FROM  VirtualTable

OPEN @CURSOR

FETCH NEXT FROM @CURSOR INTO @FNAME, @SNAME, @FACNAME

CLOSE @CURSOR

EXEC MyProcedure;




SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
BEGIN TRANSACTION
    UPDATE Student
        SET MarkBookCode = 228
        WHERE MarkBookCode = 1

    IF (@@error <> 0)	
        ROLLBACK
COMMIT

SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
BEGIN TRANSACTION;

    INSERT INTO Faculty(FullName, ShortName) VALUES('Faculty007', 'F007')
    SAVE TRANSACTION a;

    INSERT INTO Bachelour(FullName, ShortName) VALUES('Bachelour07', 'B07')
    SAVE TRANSACTION b;

    INSERT INTO Faculty(FullName, ShortName) VALUES('Faculty008', 'F008')
    ROLLBACK TRANSACTION b;

COMMIT TRANSACTION;



READ UNCOMMITTED
READ COMMITTED
REPEATABLE READ
SERIALIZABLE
SNAPSHOT