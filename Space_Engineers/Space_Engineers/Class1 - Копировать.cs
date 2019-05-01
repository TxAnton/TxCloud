using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using VRageMath;
using VRage.Game;
using Sandbox.ModAPI.Interfaces;
using Sandbox.ModAPI.Ingame;
using Sandbox.Game.EntityComponents;
using VRage.Game.Components;
using VRage.Collections;
using VRage.Game.ObjectBuilders.Definitions;
using VRage.Game.ModAPI.Ingame;
using SpaceEngineers.Game.ModAPI.Ingame;
public sealed class Program : MyGridProgram
{
    // НАЧАЛО СКРИПТА

    //Vector3D GravityVector;
    IMyShipController Cockpit;
    List<IMyGyro> Gyros;
    float k = 5;

    Vector3D Target = new Vector3D(-50000, 100000, -4000);
    //Vector3D Target = new Vector3D(0,0,0);

    //находим нужные блоки
    public Program()
    {
        Gyros = new List<IMyGyro>();
        GridTerminalSystem.GetBlocksOfType<IMyGyro>(Gyros);
        Cockpit = GridTerminalSystem.GetBlockWithName("Cockpit") as IMyCockpit;
        Runtime.UpdateFrequency = UpdateFrequency.Update1;

    }

    //в главной функции запускаем скрипт в рабочем режиме или останавливаем в зависимости от аргумента
    public void Main(string argument, UpdateType uType)
    {
        Vector3D GravityVector = Cockpit.GetNaturalGravity();
        Vector3D GravNorm = Vector3D.Normalize(GravityVector);

        Vector3D T = Vector3D.Normalize(Target - Cockpit.GetPosition());

        double tF = T.Dot(Cockpit.WorldMatrix.Forward);
        double tL = T.Dot(Cockpit.WorldMatrix.Left);
        double tU = T.Dot(Cockpit.WorldMatrix.Up);

        double gD = GravNorm.Dot(Cockpit.WorldMatrix.Down);
        double gL = GravNorm.Dot(Cockpit.WorldMatrix.Left);
        double gF = GravNorm.Dot(Cockpit.WorldMatrix.Forward);

        //double tRoll = Cockpit.RollIndicator;
        double tRoll = Math.Atan2(gL, gD) * k;
        //double tPitch = -Math.Atan2(tU, tF) * k;
        double tPitch = -Math.Atan2(gF, gD) * k;
        //double tYaw = -Math.Atan2(tL, tF) * k;
        double tYaw = Cockpit.RotationIndicator.X;

        foreach (IMyGyro Gyro in Gyros)
        {
            Gyro.GyroOverride = true;
            Gyro.Roll = (float)tRoll;
            Gyro.Pitch = (float)tPitch;
            Gyro.Yaw = (float)tYaw;
        }
    }

    // КОНЕЦ СКРИПТА
}