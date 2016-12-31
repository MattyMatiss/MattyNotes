-- --------------------------------------------------------
-- Хост:                         127.0.0.1
-- Версия сервера:               5.5.53 - MySQL Community Server (GPL)
-- Операционная система:         Win32
-- HeidiSQL Версия:              9.4.0.5125
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- Дамп структуры базы данных MattyNotes
CREATE DATABASE IF NOT EXISTS `mattynotes` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `MattyNotes`;

-- Дамп структуры для таблица MattyNotes.NoteTypes
DROP TABLE IF EXISTS `NoteTypes`;
CREATE TABLE IF NOT EXISTS `NoteTypes` (
  `TypeId` int(11) NOT NULL AUTO_INCREMENT,
  `TypeName` text,
  PRIMARY KEY (`TypeId`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

-- Дамп данных таблицы MattyNotes.NoteTypes: ~8 rows (приблизительно)
DELETE FROM `NoteTypes`;
/*!40000 ALTER TABLE `NoteTypes` DISABLE KEYS */;
INSERT INTO `NoteTypes` (`TypeId`, `TypeName`) VALUES
	(1, 'Работа'),
	(2, 'Семья'),
	(3, 'Отдых'),
	(4, 'Другое'),
	(6, 'Друзья'),
	(7, 'Еда'),
	(8, 'Программирование'),
	(9, 'Обучение');
/*!40000 ALTER TABLE `NoteTypes` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
