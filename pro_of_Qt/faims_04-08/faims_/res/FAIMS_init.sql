-- MySQL dump 10.13  Distrib 5.7.25, for Win64 (x86_64)
--
-- Host: localhost    Database: FAIMS
-- ------------------------------------------------------
-- Server version	5.7.25

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `spectrogram_data`
--

/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE if not exists `spectrogram_data` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `table_name` varchar(50) NOT NULL COMMENT '数据表名称',
  `gas_type` varchar(50) NOT NULL COMMENT '气体类别',
  `gas_volume` varchar(50) NOT NULL COMMENT '气体体积',
  `remarks` varchar(100) NOT NULL COMMENT '备注信息',
  `data_lenth` int(11) NOT NULL COMMENT '单条数据长度',
  `curves_number` int NOT NULL COMMENT '曲线条数',
  `time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `spectrogram_data`
--

LOCK TABLES `spectrogram_data` WRITE;
/*!40000 ALTER TABLE `spectrogram_data` DISABLE KEYS */;
/*!40000 ALTER TABLE `spectrogram_data` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `fingerprint_spectrum`
--

/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE if not exists `fingerprint_spectrum` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `table_name` varchar(40) NOT NULL COMMENT '数据表名称',
  `remarks` varchar(50) NOT NULL COMMENT '备注信息',
  `time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `fingerprint_spectrum`
--

LOCK TABLES `fingerprint_spectrum` WRITE;
/*!40000 ALTER TABLE `fingerprint_spectrum` DISABLE KEYS */;
/*!40000 ALTER TABLE `fingerprint_spectrum` ENABLE KEYS */;
UNLOCK TABLES;


--
-- Table structure for table `warehousing_log`
--

/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE if not exists `warehousing_log` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `data_type` varchar(40) NOT NULL COMMENT '数据类型',
  `remarks` varchar(50) NOT NULL COMMENT '备注信息',
  `time` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `warehousing_log`
--

LOCK TABLES `warehousing_log` WRITE;
/*!40000 ALTER TABLE `warehousing_log` DISABLE KEYS */;
/*!40000 ALTER TABLE `warehousing_log` ENABLE KEYS */;
UNLOCK TABLES;

-- Dump completed on 2020-11-11 15:40:32
