USE [master]
GO
/****** Object:  Database [Employee_cardfiles]    Script Date: 6/3/2023 7:36:21 PM ******/
CREATE DATABASE [Employee_cardfiles]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'Employee_cardfiles', FILENAME = N'D:\Programs\sql server\MSSQL15.SQLEXPRESS\MSSQL\DATA\Employee_cardfiles.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'Employee_cardfiles_log', FILENAME = N'D:\Programs\sql server\MSSQL15.SQLEXPRESS\MSSQL\DATA\Employee_cardfiles_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT
GO
ALTER DATABASE [Employee_cardfiles] SET COMPATIBILITY_LEVEL = 150
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [Employee_cardfiles].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [Employee_cardfiles] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET ARITHABORT OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [Employee_cardfiles] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [Employee_cardfiles] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET  DISABLE_BROKER 
GO
ALTER DATABASE [Employee_cardfiles] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [Employee_cardfiles] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [Employee_cardfiles] SET  MULTI_USER 
GO
ALTER DATABASE [Employee_cardfiles] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [Employee_cardfiles] SET DB_CHAINING OFF 
GO
ALTER DATABASE [Employee_cardfiles] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [Employee_cardfiles] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [Employee_cardfiles] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [Employee_cardfiles] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
ALTER DATABASE [Employee_cardfiles] SET QUERY_STORE = OFF
GO
USE [Employee_cardfiles]
GO
/****** Object:  User [user]    Script Date: 6/3/2023 7:36:21 PM ******/
CREATE USER [user] FOR LOGIN [user] WITH DEFAULT_SCHEMA=[dbo]
GO
/****** Object:  User [db_admin]    Script Date: 6/3/2023 7:36:21 PM ******/
CREATE USER [db_admin] FOR LOGIN [db_admin] WITH DEFAULT_SCHEMA=[dbo]
GO
/****** Object:  Table [dbo].[Education]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Education](
	[EducationID] [int] IDENTITY(1,1) NOT NULL,
	[EmployeeID] [int] NOT NULL,
	[TypeID] [int] NOT NULL,
	[Institution] [nvarchar](max) NOT NULL,
	[Speciality] [nvarchar](max) NULL,
PRIMARY KEY CLUSTERED 
(
	[EducationID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[EducationTypes]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[EducationTypes](
	[TypeID] [int] IDENTITY(1,1) NOT NULL,
	[TypeDesc] [nvarchar](max) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[TypeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Employees]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Employees](
	[EmployeeID] [int] IDENTITY(1,1) NOT NULL,
	[FirstName] [nvarchar](max) NOT NULL,
	[LastName] [nvarchar](max) NOT NULL,
	[Patronymic] [nvarchar](max) NULL,
	[GenderID] [int] NOT NULL,
	[Birthdate] [date] NOT NULL,
	[JobID] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[EmployeeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Experience]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Experience](
	[WorkOrderID] [int] IDENTITY(1,1) NOT NULL,
	[EmployeeID] [int] NOT NULL,
	[Job] [nvarchar](max) NOT NULL,
	[StartDate] [date] NOT NULL,
	[EndDate] [date] NOT NULL,
	[Company] [nvarchar](max) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[WorkOrderID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Genders]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Genders](
	[GenderID] [int] IDENTITY(1,1) NOT NULL,
	[GenderDesc] [nvarchar](max) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[GenderID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Jobs]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Jobs](
	[JobID] [int] IDENTITY(1,1) NOT NULL,
	[JobDesc] [nvarchar](max) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[JobID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Index [ix_education]    Script Date: 6/3/2023 7:36:21 PM ******/
CREATE UNIQUE NONCLUSTERED INDEX [ix_education] ON [dbo].[Education]
(
	[EducationID] DESC,
	[EmployeeID] ASC,
	[TypeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [ix_birth]    Script Date: 6/3/2023 7:36:21 PM ******/
CREATE NONCLUSTERED INDEX [ix_birth] ON [dbo].[Employees]
(
	[Birthdate] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [IX_Employees_inc]    Script Date: 6/3/2023 7:36:21 PM ******/
CREATE NONCLUSTERED INDEX [IX_Employees_inc] ON [dbo].[Employees]
(
	[EmployeeID] ASC
)
INCLUDE([FirstName],[LastName],[Patronymic],[JobID]) WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
ALTER TABLE [dbo].[Education]  WITH CHECK ADD  CONSTRAINT [FK_Education_EducationTypes] FOREIGN KEY([TypeID])
REFERENCES [dbo].[EducationTypes] ([TypeID])
GO
ALTER TABLE [dbo].[Education] CHECK CONSTRAINT [FK_Education_EducationTypes]
GO
ALTER TABLE [dbo].[Education]  WITH CHECK ADD  CONSTRAINT [FK_Education_Employees] FOREIGN KEY([EmployeeID])
REFERENCES [dbo].[Employees] ([EmployeeID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Education] CHECK CONSTRAINT [FK_Education_Employees]
GO
ALTER TABLE [dbo].[Employees]  WITH CHECK ADD  CONSTRAINT [FK_Employees_Genders] FOREIGN KEY([GenderID])
REFERENCES [dbo].[Genders] ([GenderID])
GO
ALTER TABLE [dbo].[Employees] CHECK CONSTRAINT [FK_Employees_Genders]
GO
ALTER TABLE [dbo].[Employees]  WITH CHECK ADD  CONSTRAINT [FK_Employees_Jobs] FOREIGN KEY([JobID])
REFERENCES [dbo].[Jobs] ([JobID])
GO
ALTER TABLE [dbo].[Employees] CHECK CONSTRAINT [FK_Employees_Jobs]
GO
ALTER TABLE [dbo].[Experience]  WITH CHECK ADD  CONSTRAINT [FK_Experience_Employees] FOREIGN KEY([EmployeeID])
REFERENCES [dbo].[Employees] ([EmployeeID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Experience] CHECK CONSTRAINT [FK_Experience_Employees]
GO
/****** Object:  StoredProcedure [dbo].[AgeJob]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[AgeJob] AS
BEGIN
    SELECT FirstName, LastName, datediff(year, BirthDate, Getdate()) as Age, JobDesc 
    FROM Employees inner join Jobs on Employees.JobID=Jobs.JobID
END;
GO
/****** Object:  StoredProcedure [dbo].[ChangeEducations]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[ChangeEducations]
 (@educationID int, @employeeId int, @typeId int, @institution text, @speciality text)
 AS
 BEGIN
UPDATE Education SET EmployeeId=@employeeId, TypeId=@typeId, Institution=@institution, Speciality=@speciality
WHERE EducationID=@educationID
END
GO
/****** Object:  StoredProcedure [dbo].[ChangeEmployees]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[ChangeEmployees]
 (@EmployeeID int, @fname text, @lname text, @pname text, @genderId int, @birth date, @jobId int)
 AS
 BEGIN
 UPDATE Employees SET FirstName=@fname, LastName=@lname, Patronymic=@pname, GenderID=@genderId, Birthdate=@birth, JobID=@jobId
	where EmployeeID = @EmployeeID
END
GO
/****** Object:  StoredProcedure [dbo].[ChangeExperiences]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[ChangeExperiences]
 (@workorder int, @employeeId int, @job text, @start date, @end date, @company text)
 AS
 BEGIN
UPDATE Experience SET EmployeeId=@employeeId, Job=@job, StartDate=@start, EndDate=@end, Company=@company
WHERE WorkOrderID=@workorder
END
GO
/****** Object:  StoredProcedure [dbo].[ChangeJobs]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[ChangeJobs]
 (@jobID int, @jobDesc text) 
 AS
 BEGIN
 UPDATE Jobs SET JobDesc=@jobDesc WHERE JobID=@jobID
END
GO
/****** Object:  StoredProcedure [dbo].[CreateEducation]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[CreateEducation]
 (@employeeId int, @typeId int, @institution text, @speciality text)
 AS
 BEGIN
 INSERT INTO Education (EmployeeId, TypeId, Institution, Speciality)
 values (@employeeId, @typeId, @institution, @speciality)
END
GO
/****** Object:  StoredProcedure [dbo].[CreateEmployee]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[CreateEmployee]
 (@fname text, @lname text, @pname text, @genderId int, @birth date, @jobId int)
 AS
 BEGIN
 INSERT INTO Employees (FirstName, LastName, Patronymic, GenderID, Birthdate, JobID)
 values (@fname, @lname, @pname, @genderId, @birth, @jobId)
END
GO
/****** Object:  StoredProcedure [dbo].[CreateExperience]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[CreateExperience]
 (@employeeId int, @job text, @start date, @end date, @company text)
 AS
 BEGIN
 INSERT INTO Experience (EmployeeId, Job, StartDate, EndDate, Company)
 values (@employeeId, @job, @start, @end, @company)
END
GO
/****** Object:  StoredProcedure [dbo].[CreateJob]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[CreateJob]
 (@jobDesc text) 
 AS
 BEGIN
 INSERT INTO Jobs (JobDesc)
 values (@jobDesc)
END
GO
/****** Object:  StoredProcedure [dbo].[DeleteProcedureEducation]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[DeleteProcedureEducation]
 (
 @EducationID int
 )
 AS
 BEGIN
 DELETE Education WHERE EducationID=@EducationID
END
GO
/****** Object:  StoredProcedure [dbo].[DeleteProcedureEmployees]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[DeleteProcedureEmployees]
 (
 @EmployeeID int
 )
 AS
 BEGIN
 DELETE Employees WHERE EmployeeID=@EmployeeID
END
GO
/****** Object:  StoredProcedure [dbo].[DeleteProcedureExperience]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[DeleteProcedureExperience]
 (
 @WorkOrderID int
 )
 AS
 BEGIN
 DELETE Experience WHERE WorkOrderID=@WorkOrderID
END
GO
/****** Object:  StoredProcedure [dbo].[DeleteProcedureJobs]    Script Date: 6/3/2023 7:36:21 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[DeleteProcedureJobs]
 (
 @JobID int
 )
 AS
 BEGIN
 DELETE Jobs WHERE JobID=@JobID
END
GO
USE [master]
GO
ALTER DATABASE [Employee_cardfiles] SET  READ_WRITE 
GO
